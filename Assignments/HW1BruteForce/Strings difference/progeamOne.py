from collections import Counter
LOG = lambda x: print(x)

def generate_strings(str_size: int, ones_num: int, strings_list: list[str], dum_str: str) -> None:
    if len(dum_str) == str_size:
        if Counter(dum_str)["1"] == ones_num:
            strings_list.append(dum_str)
        else:
            return None
    generate_strings(str_size, ones_num, strings_list, dum_str+"0")
    generate_strings(str_size, ones_num, strings_list, dum_str+"1")

if __name__=='__main__':
    str_size, ones_num = (int(x) for x in input().split())
    strings_list = []
    dum_str = ""
    generate_strings(str_size, ones_num, strings_list, dum_str)
    LOG(strings_list)