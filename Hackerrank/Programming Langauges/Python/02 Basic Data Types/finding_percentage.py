
def calculate_average(student_marks, query_name):
    answer = sum(student_marks[query_name])/len(student_marks[query_name])
    answer = "{0:.2f}".format(answer)
    return answer


if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()

    print(calculate_average(student_marks, query_name))
