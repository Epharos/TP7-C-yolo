import os

files = list()

for f in os.listdir(os.getcwd()) :
	if f.endswith('.cpp') and f != 'main.cpp' :
		files.append(f[:len(f) - 4])
		os.system('g++ -c ' + f)
		print 'Compiling [' + f + ']'

command = 'g++ -std=c++11 main.cpp -o main.exe'

for n in files :
	command += ' ' + n + '.o'

print 'Executing [' + command + ']'
os.system(command)

print 'Launching ...\n\n'
os.system('main.exe')