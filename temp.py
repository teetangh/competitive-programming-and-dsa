# Python program to create
# sparse matrix using csr_matrix()

# Import required package
import numpy as np
from scipy.sparse import csr_matrix

# Creating a 3 * 4 sparse matrix
# sparseMatrix = csr_matrix((1, 10),
#                           dtype=np.int8).toarray()

sparseMatrix = np.random.randint(3, size=(1, 100))

# Print the sparse matrix
print(sparseMatrix)

np.sort(sparseMatrix)

print(sparseMatrix)
