read_line = input().split()
N = int(read_line[0])
day_limit = int(read_line[1])
rate = int(read_line[2])##
while N != 0 and day_limit != 0 and rate != 0:
    daily_routes = [int(x) for x in input().split()]
    evening_routes = [int(x) for x in input().split()]

    daily_routes.sort()
    evening_routes.sort(reverse=True)

    total_overtime = []
    for idx in range(N):
        element = (daily_routes[idx] + evening_routes[idx]) - day_limit \
            if (daily_routes[idx] + evening_routes[idx]) > day_limit else 0
        total_overtime.append(element)

    print(sum(total_overtime) * rate)

    read_line = input().split()
    N = int(read_line[0])
    day_limit = int(read_line[1])
    rate = int(read_line[2])
