import queue

##
N = int(input())

while N != 0:

    q = queue.PriorityQueue(maxsize=N)
    numbers = [int(x) for x in input().split()]

    for n in numbers:
        q.put(n)

    sum_list = []

    for _n in range(N - 1):
        a = q.get()
        b = q.get()
        q.put(a + b)
        sum_list.append(a + b)
        if q.qsize() == 1:
            break

    print(sum(sum_list))

    N = int(input())
