str = "mnesi___ya__k____mime"
N = 3

# generate the matrix
#complexity: O(n)
row_sz = int(len(str)/3)
mat = []
for n in range(N): 
    mat.append(str[n * row_sz: (n+1) * row_sz] + str[n * row_sz: (n+1) * row_sz])

ret_str = ""
for i in range(row_sz): 
    ret_str += mat[0][i]
    ret_str += mat[1][i+1]
    ret_str += mat[2][i+2]

ret_str = ret_str.replace("_", " ")
print(ret_str)
