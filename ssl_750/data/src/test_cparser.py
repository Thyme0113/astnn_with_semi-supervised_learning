import os
from iniconfig import ParseError
from pycparser import c_parser
from pycparser.plyparser import ParseError

parser = c_parser.CParser()


abs_cwd = os.getcwd()
child_dir_list = os.listdir(abs_cwd)
for obj in child_dir_list:
	if obj != 'gcd':
		continue
	if os.path.isdir(obj) and not obj.startswith('.'):
		abs_child_dir = os.path.join(abs_cwd, obj)
		child_file_list = os.listdir(abs_child_dir)
		for file in child_file_list:
			# if not 'loop' in file:
			# 	continue
			abs_child_file = os.path.join(abs_child_dir, file)
			if os.path.isfile(abs_child_file):
				with open(abs_child_file) as f:
					code = f.read()
					try:
						ast = parser.parse(code)
					except ParseError:
						print(abs_child_file)
# code  = """
# int gcd(int a,int b){
#     return b?gcd(b,a%b):a;
# }

# signed main(){
#     int x,y;
#     cin>>x>>y;
#     cout<<gcd(x,y)<<endl;
#     return 0;
# }
# """

# ast = parser.parse(code)