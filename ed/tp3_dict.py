def decodificate(morse_code):
  letter_in_morse = ''
  for line in morse_code:
    for bip in line:
      if letter_in_morse == '/':
        print(' ', end='')
        letter_in_morse = ''
      elif bip == ' ':
        print(morse_dict[letter_in_morse], end='')
        letter_in_morse = ''
      else:
        letter_in_morse += bip
    print(morse_dict[letter_in_morse])
    letter_in_morse = ''

def create_morse_dict(path):
  morse_file = open(path, 'r')
  char, sequence = '', ''
  created_morse_dict = {}
  for line in morse_file:
    for i in range(len(line)):
      bip = line[i]
      if i == 0:
        char = bip
      elif bip in {'.', '-'}:
        sequence += bip
    created_morse_dict[sequence] = char
    sequence = ''
  return created_morse_dict

# "MAIN"
morse_input = []
while True:
    try:
        line = input()
    except EOFError:
        break
    morse_input.append(line)

morse_dict = create_morse_dict('./src/morse.txt')
decodificate(morse_input)
