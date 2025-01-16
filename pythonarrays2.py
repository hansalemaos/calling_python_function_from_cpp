from array import array
from ctypes import CDLL, c_size_t,PYFUNCTYPE,c_int,c_int64,c_void_p
@PYFUNCTYPE(c_int, c_int64)
def append_to_result(valor):
    resultlist.append(valor)
    return 0
resultlist=[]
caminho_dll = r"mytest.dll"
testlib = CDLL(caminho_dll)
testlib.add_vecs_int.restype = None
testlib.add_vecs_int.argtypes = [
    c_size_t,
    c_size_t,
    c_size_t,
    c_size_t,
    c_void_p,
]
list1 = array("q", (range(100)))
list2 = array("q", (range(100)))
testlib.add_vecs_int(*list1.buffer_info(), *list2.buffer_info(), append_to_result)
print(resultlist)
