def switch(s):
    new = ""
    for i in range(0, len(s)):
        if s[i].islower() == True:
            new += s[i].upper()
        elif s[i].isupper() == True:
            new += s[i].lower()
        elif s[i].isalnum() == True:
            new += ""
        else:
            new += ""
    return new
if  __name__ == "__main__":
    ans = switch('aB@1. a')
    print(ans)