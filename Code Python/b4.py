def count(a):
    n=len(a)
    if n<2:
        return 0
    left=a[:n//2]
    right=a[n//2:]
    ans=0
    ans+=count(left)
    ans+=count(right)

    i=0
    j=0
    k=0
    while i<len(left) and j<len(right):
        if left[i]<=right[j]:
            a[k]=left[i]
            i+=1
            k+=1
        else:
            a[k]=right[j]
            j+=1
            k+=1
            ans+=len(left)-i
    if i<len(left):
        a[k:]=left[i:]
    if j<len(right):
        a[k:]=right[j:]
    return ans

print(count([2,3,8,6,1]))