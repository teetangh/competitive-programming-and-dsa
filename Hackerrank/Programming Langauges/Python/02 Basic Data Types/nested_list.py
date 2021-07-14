
def second_lowest_grade(students):

    worst = 9999999
    worst2 = 9999999

    for i in range(len(students)):
        if worst > students[i][1]:
            worst = students[i][1]

    for i in range(len(students)):
        if worst2 > students[i][1] and students[i][1] > worst:
            worst2 = students[i][1]

    answer = []
    for i in range(len(students)):
        if worst2 == students[i][1]:
            answer.append(students[i][0])

    answer.sort()

    return answer


if __name__ == '__main__':
    students = []

    for _ in range(int(input())):
        current = []
        name = input()
        score = float(input())

        current = [name, score]
        students.append(current)

    answer = second_lowest_grade(students)

    for i in answer:
        print(i)
