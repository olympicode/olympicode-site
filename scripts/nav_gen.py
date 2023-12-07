import os
import functools

include_list = ['2013/2014', '2015/2016', '2016/2017', '2017/2018', '2019/2020', '2020/2021']

def processFileName(path):
    with open(path, "r") as fl:
        fl_content = list(fl)
        fl_content = list(filter(lambda x: x.strip().startswith('#'), fl_content))
        if len(fl_content) == 0:
            return ""
        return fl_content[0].strip()[2:]

def processTakprogContest(path): 
    taskList = []
    with os.scandir(path) as tasks:
        for task in tasks:
            if task.is_file() and task.name.endswith('.md'):
                taskList.append((processFileName(task.path), task.path[8:]))
    return taskList

def processTakprogSeason(path): 
    contestDict = {}
    with os.scandir(path) as contests:
        for contest in contests:
            if contest.is_dir():
                contestDict[contest.name] = processTakprogContest(contest.path)
    return contestDict

def task_compare(x, y):
    if x[0] == y[0]: 
        return 0
    if x[0][0] == 'B' and y[0][0] == 'A':
        return -1
    if x[0][0] == 'A' and y[0][0] == 'B':
        return +1
    if x[0] < y[0]:
        return -1
    return +1

def processTakprog(nav): 
    prefix = "docs/takprog"
    seasons = {}
    with os.scandir(prefix) as years:
        for season in years:
            if season.is_dir():
                seasons[season.name.replace('_','/')] = processTakprogSeason(season.path)

    sorted_keys = list(seasons.keys())
    sorted_keys.sort()
    for key1 in sorted_keys:
        if key1 in include_list:
            nav.write("  - "+key1+'\n')
            if 'kv1' in seasons[key1].keys():
                if 'kv2' in seasons[key1].keys():
                    nav.write("    - Kvalifikacije 1\n")
                else:
                    nav.write("    - Kvalifikacije\n")
                key2 = 'kv1'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'kv2' in seasons[key1].keys():
                nav.write("    - Kvalifikacije 2\n")
                key2 = 'kv2'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'kv3' in seasons[key1].keys():
                nav.write("    - Kvalifikacije 3\n")
                key2 = 'kv3'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'okr' in seasons[key1].keys():
                nav.write("    - Okružno\n")
                key2 = 'okr'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'drz' in seasons[key1].keys():
                nav.write("    - Državno\n")
                key2 = 'drz'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'sio' in seasons[key1].keys():
                nav.write("    - SIO\n")
                key2 = 'sio'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'ejoi_izb' in seasons[key1].keys():
                nav.write("    - EJOI izborno\n")
                key2 = 'ejoi_izb'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")
            if 'egoi_izb' in seasons[key1].keys():
                nav.write("    - EGOI izborno\n")
                key2 = 'egoi_izb'
                seasons[key1][key2] = sorted(seasons[key1][key2], key=functools.cmp_to_key(task_compare))
                for key3 in seasons[key1][key2]:
                    nav.write("      - ["+key3[0]+"]("+key3[1]+")\n")

print(os.getcwd())
with open("docs/nav.md", "w") as nav:
    nav.write("---\n")
    nav.write("search:\n")
    nav.write("  exclude: true\n")
    nav.write("---\n")
    nav.write("\n")

    nav.write("- Početna\n")
    nav.write("  - [Početna](index.md)\n")
    nav.write("- Takprog\n")
    nav.write("  - [Takprog Arhiva](takprog/index.md)\n")

    processTakprog(nav)
