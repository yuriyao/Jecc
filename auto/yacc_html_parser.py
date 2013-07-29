# -*- coding:utf-8 -*-
#解析编译工作台生成的html文件
from bs4 import BeautifulSoup

class Yacc_Html_Parser(object):
	def __init__(self, html_name):
		context = ''
		if type(html_name) is str:
			fp = open(html_name)
			context = fp.read().decode('utf8')
		elif type(html_name) is file:
			context = html_name.read().decode('utf8')
		self.soup = BeautifulSoup(context)
		self.parse()

	def parse(self):
		infos = []
		trs = self.soup.find_all('tr')
		#获得action和goto表的表项数
		tds = trs[0].find_all('td')
		action_num = int(tds[1]['colspan'])
		goto_num = int(tds[2]['colspan'])
		tds = trs[1].find_all('td')
		for td in tds:
			infos.append(str(td.string))
		#获得action和goto表的标题
		self.action = infos[0 : action_num]
		self.goto = infos[action_num : action_num + goto_num]
		#获得状态信息
		self.states = []
		for i in xrange(2, len(trs)):
			tds = trs[i].find_all('td')
			t = []
			i = 0
			for td in tds:
				if i == 0:
					i = 1
					continue
				t.append(td.string)
			self.states.append(t)

	def get_action(self):
		return self.action
	def get_goto(self):
		return self.goto
	def get_states(self):
		return self.states

if __name__ == '__main__':
	hp = Yacc_Html_Parser('index.html')
	print hp.get_goto()
	print hp.get_action()
	print hp.get_states()