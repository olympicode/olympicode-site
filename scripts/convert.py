# Napraviti index.txt i staviti u docs root
# Imenovati foldere kval-1, kval-2, kval-3, okr, drz, sio, ejoi_izb, egoi_izb
# Tri fajla po zadatku:
#   - sifra-st.md
#   - sifra-sol.md
#   - sifra.cpp
# Iz st i sol obrisati sve informacije sem teksta/rešenja
# (naziv zadatka, autore, testere...)
# Ispraviti nivoe naslova
# Pustiti ovu skriptu iz docs root

#---
#hide:
#   - toc
#---
#
## Naslov
#
#=== Zadatak
#
#   | Vremensko ograničenje | Memorijsko ograničenje | 
#   |:-:|:-:|
#   | 1000ms | 256MB | 
#
#   STATEMENT CONTENT
#
#=== Rešenje
#
#   | Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |
#   |:-:|:-:|:-:|:-:|
#   | Pavle Martinović | Pavle Martinović | Mladen Puzić | Tadija Šebez |
#
#   SOLUTION CONTENT
#
#   ``` cpp title="us-open.cpp" linenums="1"
#
#   ```

# sezona, takm, sifra, naslov, autor, tekst, analiza, testiranje

import string
import os

def process(line):
    return "".join(filter(lambda x: x.isprintable(), line))

def latinica(line):
    dictt = {'а':'a', 'б':'b', 'в':'v', 'г':'g', 'д':'d',
     'ђ':'đ', 'е':'e', 'ж':'ž', 'з':'z', 'и':'i',
     'ј':'j', 'к':'k', 'л':'l', 'љ':'lj', 'м':'m',
     'н':'n', 'њ':'nj', 'о':'o', 'п':'p', 'р':'r',
     'с':'s', 'т':'t', 'ћ':'ć', 'у':'u', 'ф':'f',
     'х':'h', 'ц':'c', 'ч':'č', 'џ':'dž', 'ш':'š', 
     'А':'A', 'Б':'B', 'В':'V', 'Г':'G', 'Д':'D',
     'Ђ':'Đ', 'Е':'E', 'Ж':'Ž', 'З':'Z', 'И':'I',
     'Ј':'J', 'К':'K', 'Л':'L', 'Љ':'Lj', 'М':'M',
     'Н':'N', 'Њ':'Nj', 'О':'O', 'П':'P', 'Р':'R',
     'С':'S', 'Т':'T', 'Ћ':'Ć', 'У':'U', 'Ф':'F',
     'Х':'H', 'Ц':'C', 'Ч':'Č', 'Џ':'Dž', 'Ш':'Š'}
    
    table  = str.maketrans(dictt)
    return line.translate(table)


with open("convert_list.txt", "r") as tasks_file:
    tasks = list(tasks_file)

for task_line in tasks:
    task_split = task_line.split(sep='|')
    
    sezona = task_split[0].replace('/', '_').strip() # TRIMUJ SVE OVO
    takm = task_split[1].strip()
    sifra = task_split[2].strip()
    naslov = task_split[3].strip()
    autor = task_split[4].strip()
    tekst = task_split[5].strip()
    analiza = task_split[6].strip()
    testiranje = task_split[7].strip()
    vogr = task_split[8].strip()
    mogr = task_split[9].strip()

    dir_path = os.path.dirname(os.path.realpath(__file__))
    prefix = os.path.abspath(dir_path)+'/../docs/takprog/'+sezona+'/'+takm+'/'
    with open(prefix+sifra+"-st.md", "r") as statement:
        statement_content = list(statement)
    with open(prefix+sifra+"-sol.md", "r") as solution:
        solution_content = list(solution)
    with open(prefix+sifra+".cpp", "r") as code:
        code_content = list(code)

    for i in range(0, len(statement_content)):
        statement_content[i] = latinica(statement_content[i])

    for i in range(0, len(solution_content)):
        solution_content[i] = latinica(solution_content[i])

    result = []

    result.append('---\n')
    result.append('hide:\n')
    result.append('  - toc\n')
    result.append('---\n')
    result.append('\n')

    result.append('# ' + naslov + '\n')
    result.append('\n')

    result.append('=== "Zadatak"\n')
    result.append('\t\n')

    result.append('\t| Vremensko ograničenje | Memorijsko ograničenje |\n')
    result.append('\t|:-:|:-:|\n')
    result.append('\t| ' + vogr + ' | ' + mogr + ' |\n')
    result.append('\t\n')

    for line in statement_content:
        result.append('\t' + process(line) +'\n')

    result.append('\t\n')

    result.append('=== "Rešenje"\n')
    result.append('\t\n')

    result.append('\t| Autor | Tekst i test primeri | Analiza rеšenja | Testiranje |\n')
    result.append('\t|:-:|:-:|:-:|:-:|\n')
    result.append('\t| ' + autor + ' | ' + tekst + ' | ' + analiza + ' | ' + testiranje + ' |\n')
    result.append('\t\n')

    for line in solution_content:
        result.append('\t' + process(line) +'\n')

    result.append('\t\n')

    result.append('\t``` cpp title="' + sifra + '.cpp" linenums="1"\n')
    
    for line in code_content:
        result.append('\t' + line)

    result.append('\n\t```\n')
    with open(prefix+sifra+".md", "w") as result_file:
        for line in result:
            result_file.write(line)
