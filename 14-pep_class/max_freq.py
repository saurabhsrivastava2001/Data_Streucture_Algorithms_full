from collections import defaultdict

count = defaultdict(int)

def exist(arr):
    count = defaultdict(int)
    ls_freq=[]
    for i in arr:
        count[i]+=1
    for value in count.values:
        ls_freq.append(value)    

def max_freq(arr):
    minSub=10000
    for i in range (0,len(arr)):
        subarr=[]
        for j in range(i,len(arr)):
            subarr.append(arr[j])
            if len(subarr)>=3:
                if (exist(subarr)):
                    minSub=min(minSub,len(subarr))


if (__name__)=='__main__':
    arr=[1,1,2,2,3,3,5,3,5]