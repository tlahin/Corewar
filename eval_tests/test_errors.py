import subprocess
import os

# Do you want to print the error messages
print_msg = False

# Define the keyword to look for in error message
error_txt = "ERROR:"

# Make and copy new corewar to this folder.
os.system('cd .. && make && cp corewar ./eval_tests/corewar && cd eval_tests')

def main():
	global error_txt

	print(yellow('Testing invalid champions'))
	test_error('Invalid header: ', './corewar ./champs/error_champs/invalid_header.cor')
	test_error('Empty file: ', './corewar ./champs/error_champs/no_code.cor')
	test_error('Code too big: ', './corewar ./champs/error_champs/too_big.cor')
	#test_error('Non-existent champion: ', './corewar ./champs/error_champs/casper.cor')

	print(yellow('\nTesting invalid input'))
	error_txt = "Incorrect usage."
	test_error('Champ without .cor: ', './corewar ./champs/champs/Gagnant')
	test_error('Negative -dump flag: ', './corewar ./champs/champs/Gagnant.cor -dump -42 ./champs/champs/turtle.cor')
	test_error('-dump flag without argument: ', './corewar -dump ./champs/champs/Gagnant.cor ./champs/champs/turtle.cor')
	test_error('Two -dump flags: ', './corewar -dump 21 ./champs/champs/Gagnant.cor -dump 42 ./champs/champs/turtle.cor')
	test_error('Same -n flag: ', './corewar -n 1 ./champs/champs/Gagnant.cor -n 1 ./champs/champs/turtle.cor')
	test_error('-n flag too big: ', './corewar ./champs/champs/Gagnant.cor -n 5 ./champs/champs/turtle.cor')
	test_error('-n flag without argument: ', './corewar -n ./champs/champs/Gagnant.cor ./champs/champs/turtle.cor')
	test_error('-n flag at the end: ', './corewar ./champs/champs/Gagnant.cor ./champs/champs/turtle.cor -n 2')


# Define colors.
def red(text):
	return '\033[31m' + text + '\033[0m'
def green(text):
	return '\033[32m' + text + '\033[0m'
def yellow(text):
	return '\033[33m' + text + '\033[0m'
def blue(text):
	return '\033[34m' + text + '\033[0m'

def test_error(description, command_str):
	print((blue(description)), end='')
	split_str = command_str.split()
	result = subprocess.run(split_str, capture_output=True)
	if result.returncode != 0 and error_txt in result.stderr.decode('utf-8'):
		print(green('OK'))
		if print_msg:
			print(red(result.stderr.decode('utf-8')))
	else:
		print(red('KO'))

main()