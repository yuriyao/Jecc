# -*- coding:utf-8 -*-
#输入编译工作台的文法和其生成的LR1分析表，自动生成程序
import sys
from yacc_html_parser import Yacc_Html_Parser
import os

#无奈的全局变量，完全是无奈之举

#处理cfg文件
#生成一个字典{"noterminal" : ['E', 'E\''], 'terminal' : ['id', '+', '*'], 'start' : ['s'], "production" : {"S" : ['E']}}
def deal_cfg(file):

	def get_index(value, iter):
		index = 0
		#print value
		for v in iter:
			if v == value:
				return index
			index += 1
		return -1

	ret = {'nonterminal' : [], 'terminal' : [], 'start' : [], 'production' : {}}
	types = ['nonterminal', 'terminal', 'start', 'production']
	NOTERMINAL = 0
	TERMINAL = 1
	START = 2
	PRODUCTION = 3
	FREE = 4
	#是否在搜集有用的信息
	state = FREE
	#pro_not_terminal = 0
	pro_buffer = ''
	#s = file.readline()
	for s in file:
		#s = s.lstrip(' ')
		if not s:
			continue
		elif s[0] == '[':
			s = s.strip()
			s = s.rstrip(']')
			s = s.lstrip('[')
			print s
			index = get_index(s, types)
			#print 'the s2 is', s, 'the index is', index
			if index >= 0:
				state = index
			continue

		if state == FREE:
			#去除空格
			s = s.replace(' ', '')
			#去掉换行
			s = s.rstrip('\n')
			#去掉注释
			s = s.split('//')[0]
			#去掉左右[]
			s = s.lstrip('[')			
			s = s.rstrip(']')
			index = get_index(s, types)
			#print 'the s is', s, 'the index is', index
			if index < 0:
				continue
			state = index
		#处理终结符
		elif state == NOTERMINAL:
			#print 'nonterminal', s
			#去除注释
			s = s.split("//")[0]

			l = s.split()
			if l:
				#print 'Noterminal:', l
				ret["nonterminal"] += l
		#处理终结符
		elif state == TERMINAL:
			#去除注释
			s = s.split('//')[0]
			l = s.split()
			if l:
				ret['terminal'] += l
		#处理开始符号
		elif state == START:
			#去除注释
			s = s.split('//')[0]
			l = s.split()
			if l:
				ret['start'] += l
		#处理产生式
		elif state == PRODUCTION:
			
			#去除注释
			s = s.split('//')[0]
			#去除左右空格
			s = s.strip()
			
			#检查产生式是否结束
			if s[-1] != ';':
				pro_buffer += ' ' + s
				continue
			pro_buffer += ' ' + s
			#去掉结尾的;
			s = pro_buffer[0 : -1]
			#清空缓存
			pro_buffer = ''
			#去除空格
			#s = s.replace(' ', '')
			#去除\t
			s = s.replace('\t', '')
			
			if not s:
				continue
			l = s.split('=>')
			if len(l) != 2:
				continue
			#去除左部非终结符的空格
			l[0] = l[0].replace(' ', '')
			#终结符还没有申明，打印waring
			if l[0] not in ret['nonterminal'] and l[0] not in ret['start']:
				print 'WARING:The nonterminal label %s is not declared' % l[0]
			d = ret['production']
			pro = l[1].split('|')
			if l[0] in d.keys():
				ret['production'][l[0]] += pro
			else:
				ret['production'][l[0]] = pro
	return ret

#生成产生式定义的代码
def generate_cfg(file, d, lr1_file):
	#获得生成式的列索引信息
	yacc_hp = Yacc_Html_Parser(lr1_file)
	#获得action表的列数
	action_len = len(yacc_hp.get_action())
	#获得goto表的表头名称
	goto = yacc_hp.get_goto()

	def get_goto_row(name):
		name = name.split('->')[0]
		i = 0
		for v in goto:
			if v == name:
				return i + action_len
			i += 1
		return -1

	production = d['production']
	#存储所有的cfg
	cfg = {}
	i = 0
	file.write('/************所有的产生式*************/\n')
	for (key, value) in production.items():
		#需要生成父产生式
		parent = -1
		if len(value) > 1:
			name = key + '->'
			for each in value:
				#each = each.strip()
				name += each + '|'
			#去掉末尾的'|'
			name = name[0 : -1]
			#存储到cfg
			cfg[name] = {'index' : i, 'parent' : -1}
			#生成父产生式的定义
			s = """const struct CFG cfg%d =\n{\n\t.name = "%s",\n\t.process = NULL,\n\t.parent = NULL,\n\t.items = -1, \n\t.row = %d\n};\n""" % (i, name, get_goto_row(name))	
			parent = i
			i += 1
			file.write(s)
		for each in value:
			each = each.strip()
			if not each:
				each = ' '
			name = key + '->' + each
			#去掉左右空白
			#name = name.strip()
			parent_name = 'NULL'
			if parent != -1:
				parent_name = '&cfg%d' % parent
			cfg[name] = {'index' : i, 'parent' : parent}
			items = len(each.split())
			s = """const struct CFG cfg%d =\n{\n\t.name = "%s",\n\t.process = NULL,\n\t.parent = %s,\n\t.items = %d,\n\t.row = %d\n};\n""" % (i, name, parent_name, items, get_goto_row(name))
			file.write(s)
			i += 1
	file.write('/***********************************/\n')
	return cfg

#处理生成的LR1表
def deal_lr1(file, cfgs):
	ret = {'goto' : None, 'action' : None, 'states' : []}
	try:
		yacc_hp = Yacc_Html_Parser(file)
	except Exception, e:
		print '解析yacc文件发生异常:', e
		sys.exit(-1)
	ret['goto'] = yacc_hp.get_goto()
	ret['action'] = yacc_hp.get_action()
	_states = yacc_hp.get_states()
	print '*************************'
	#print _states
	print '************************'
	states = []
	for s in _states:
		print 's', s
		t = []
		for v in s:
			#if not v:
			#	continue
			d = {'type' : None, 'index' : None}
			#print v
			#处理'\xa0'
			v = v.replace(u'\xa0', ' ')
			#去掉两端的空白
			v = v.strip()
			#表示错误状态
			if not v:
				d['type'] = 'error'
			#表示移进
			elif v.startswith('shift'):
				num = v.split(' ')[1]
				num = int(num)
				d['type'] = 'shift'
				d['index'] = num
			#表示接受
			elif v.startswith('accept'):
				d['type'] = 'accept'
			#表示跳转
			elif v.isdigit():
				num = int(v)
				d['type'] = 'goto'
				d['index'] = num
			#表示归约
			elif v.startswith('reduce'):
				#获得干净的cfg
				cfg = v.split('reduce')[1]
				cfg = cfg.split('->')
				cfg = cfg[0].strip() + '->' + cfg[1].strip().replace(u'\u03b5', ' ')
				#获得cfg的索引
				index = cfgs[cfg]['index']
				d['type'] = 'reduce'
				d['index'] = index
			#不可能的状态
			else:
				#print '获得一个不可能的状态'
				continue
			t.append(d)
		states.append(t)
	return states

#生成状态表的源代码
def generate_state_src(file, states):
	GI_SHIFT = 0
	GI_ACC = 1
	GI_ERR = 2
	GI_REDUCE = 3
	GI_GOTO = 4
	#定义所有的状态
	template1 = "const struct GrammerItem gi_%s =\n{\n\t.type = %s\n};\n";
	template2 = "const struct GrammerItem gi_%s =\n{\n\t.type = %s,\n\t.gi_skip = %d\n};\n"
	template3 = "const struct GrammerItem gi_%s =\n{\n\t.type = %s,\n\t.gi_cfg = &cfg%d\n};\n"
	#定义错误状态
	file.write('/*错误状态*/\n')
	file.write(template1 % ('error', 'GI_ERR'))
	#定义接受状态
	file.write('/*接受状态*/\n')
	file.write(template1 % ('accept', 'GI_ACC'))
	#需要定义的reduce表
	reduce = []
	#需要定义的移进
	shift = []
	#需要定义的goto表
	goto = []
	for v in states:
		for state in v:
			#GOTO
			if state['type'] == 'goto':
				if state['index'] not in goto:
					goto.append(state['index'])
			#shift
			elif state['type'] == 'shift':
				if state['index'] not in shift:
					shift.append(state['index'])
			#reduce
			elif state['type'] == 'reduce':
				if state['index'] not in reduce:
					reduce.append(state['index'])
	#定义goto表
	goto.sort()
	file.write('/************GOTO************/\n')
	for _goto in goto:
		file.write(template2 % ('goto' + str(_goto), 'GI_GOTO', _goto))
	#定义shift表
	shift.sort()
	file.write('/*************SHIFT***********/\n')
	for _shift in shift:
		file.write(template2 % ('shift' + str(_shift), 'GI_SHIFT', _shift))
	#定义reduce表
	reduce.sort()
	file.write('/**************REDUCE***********/\n')
	for _reduce in reduce:
		file.write(template3 % ('reduce' + str(_reduce), 'GI_REDUCE', _reduce))
	#开始正式生成表
	l = len(states[0])
	file.write('/**************好大一只状态表*************/\n')
	file.write('const struct GrammerItem* lr1_table[TABLE_COLUMNS][TABLE_ROWS] = {\n')
	column = 0
	for v in states:
		file.write('/*状态%d的行*/\n\t{\n\t' % column)
		column += 1
		row = 0
		for state in v:
			#错误
			if state['type'] == 'error':
				file.write('% 14s,' % '&gi_error')
			#接受
			elif state['type'] == 'accept':
				file.write('% 14s,' % '&gi_accept')
			#goto
			elif state['type'] == 'goto':
				file.write('% 14s,' % ('&gi_goto' + str(state['index'])))
			#reduce
			elif state['type'] == 'reduce':
				file.write('% 14s,' % ('&gi_reduce' + str(state['index'])))
			#shift
			elif state['type'] == 'shift':
				file.write('% 14s,' % ('&gi_shift' + str(state['index'])))
			else:
				print 'Bad state', state['type']
			if row % 5 == 4:
				file.write('\n\t')
			row += 1
		file.write('\n\t},\n')
	file.write('};\n')



#生成注释
def generate_common(file):
	s = """/**\n*  本代码由自动生成工具生成\n*  作者:姚逢靖\n*  版权所有,免费使用,但是，使用前\n*  如果是男生,请默念，我愿意包养靖哥哥一天\n*  如果是女生，请默念，“亲爱的靖哥哥”\n**/\n\n"""
	file.write(s)

#生成头文件
def generate_include(file):
	file.write('#include "states_table.h"\n')
	file.write('#include <stdio.h>\n')

#创建头文件
def generate_header(file, lr1):
	generate_common(file)
	file.write('#include "state.h"\n')
	file.write('/*状态表的行数*/\n')
	file.write('#define TABLE_COLUMNS %d\n' % len(lr1))
	file.write('/*状态表的列数*/\n')
	file.write('#define TABLE_ROWS %d\n' % len(lr1[0]))
	file.write('/*状态表*/\n')
	file.write('extern const struct GrammerItem* lr1_table[TABLE_COLUMNS][TABLE_ROWS];')

if __name__ == '__main__':
	if len(sys.argv) != 3:
		print 'Usage %s <CFG_FILE> <LR1_FILE>' % sys.argv[0]
		sys.exit(-1)

	cfg = sys.argv[1]
	lr1 = sys.argv[2]
	src = 'final/states_table.c'
	header = 'final/states_table.h'
	cfg_file = None
	lr1_file = None
	src_file = None
	#创建目录
	if not os.path.exists('final'):
		os.mkdir('final')

	#打开cfg文法的文件
	try:
		cfg_file = open(cfg)
	except IOError, e:
		print "无法打开文法文件", cfg
		sys.exit(-1)
	#打开lr1文件
	try:
		lr1_file = open(lr1)
	except IOError, e:
		print "无法打开lr1文件", lr1
		sys.exit(-1)
	#打开欲生成的源文件的代码
	try:
		src_file = open(src, 'w')
	except Exception, e:
		print '无法打开源代码文件', src
		sys.exit(-1)
	#打开欲生成的头文件
	try:
		header_file = open(header, 'w')
	except Exception, e:
		print '无法打开头文件', header, e
		sys.exit(-1)

	#获得cfg的处理结果
	cfg_res = deal_cfg(cfg_file)
	print cfg_res
	generate_common(src_file)
	generate_include(src_file)
	#生成cfg的定义的源代码，并返回所有的cfg
	cfg_dict = generate_cfg(src_file, cfg_res, lr1)
	print cfg_dict
	#生成状态表信息
	lr1_list = deal_lr1(lr1_file, cfg_dict)
	print lr1_list
	#生成状态表
	generate_state_src(src_file, lr1_list)
	#生成头文件
	generate_header(header_file, lr1_list)