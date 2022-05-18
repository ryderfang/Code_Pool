import importlib.util
import inspect
import glob, os
import sys

sys.path.append(os.getcwd())
from common.List.list_node import ListNode

PROBLEM_NO = 'nc1'
PROBLEM_LV = '/'
cls = None
method_name = ''

def load_module():
    global cls
    os.chdir(os.path.dirname(__file__))
    file_path = glob.glob(os.getcwd() + PROBLEM_LV + str(PROBLEM_NO) + '.*.py')[0]
    print(file_path)

    spec = importlib.util.spec_from_file_location(os.path.basename(file_path), file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    for member in inspect.getmembers(module):
        if member[0] == 'Solution':
            cls = member[1]
            break
    get_method_list(cls)

def get_method_list(cls):
    global method_name
    method_list = [attribute for attribute in dir(cls) if callable(getattr(cls, attribute)) and attribute.startswith('__') is False]
    method_name = method_list[0]

if __name__ == '__main__':
    load_module()
    sol = cls()
    cases = [
        [1, 2, 3]
    ]
    func = getattr(cls, method_name)
    for x in cases:
        ans = func(sol, ListNode.array_to_list(x))
        print(ListNode.list_to_array(ans))