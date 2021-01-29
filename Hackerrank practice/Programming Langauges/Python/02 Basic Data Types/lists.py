if __name__ == '__main__':
    N = int(input())

    answer = []
    for i in range(N):
        query = input()

        if query.split()[0] == "insert":
            answer.insert(int(query.split()[1]), int(query.split()[2]))

        elif query.split()[0] == "remove":
            element = int(query.split()[1])
            answer.remove(element)

        elif query.split()[0] == "append":
            element = int(query.split()[1])
            answer.append(element)

        elif query.split()[0] == "sort":
            answer.sort()

        elif query.split()[0] == "print":
            print(answer)

        elif query.split()[0] == "reverse":
            answer.reverse()

        elif query.split()[0] == "pop":
            answer.pop()

        # print("testing", answer)
