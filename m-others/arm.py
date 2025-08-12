num= int (input(' enter the number :'))

size=0

temp=num
while (temp>0):
    size+=1
    temp//=10
temp= num
new_num= 0
while(temp>0):
    dig = temp%10
    new_num += pow(dig,size)
    temp//=10

if new_num== num:
    print('armstrong')
else :
    print ('no')