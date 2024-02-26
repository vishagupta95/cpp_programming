# Write Python 3 code in this online editor and run it.
print("Hello world")
def solution(s):
    s.strip()
    number = "".join(s.split()).replace('-','')
    newN=''
    while(len(number)>4):
        newN=newN+number[0:3]+'-'
        number=number[3:]
    if len(number)==4:
        newN=newN+number[0:2]+'-'+number[2:]
    elif len(number)==2 or len(number)==3:
        newN=newN+number
    print(newN)
    


solution('00-44  4 8 5555 8361')


