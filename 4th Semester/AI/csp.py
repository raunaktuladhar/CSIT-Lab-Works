def backtracking_search(variables, domains, constraints):
    return backtrack({}, variables, domains, constraints)

def backtrack(assignment, variables, domains, constraints):
    if len(assignment) == len(variables):
        return assignment

    var = select_unassigned_variable(assignment, variables)
    for value in order_domain_values(var, assignment, domains):
        assignment[var] = value
        if is_consistent(var, value, assignment, constraints):
            result = backtrack(assignment, variables, domains, constraints)
            if result is not None:
                return result
        del assignment[var]  # Backtrack
    return None

def select_unassigned_variable(assignment, variables):
    for var in variables:
        if var not in assignment:
            return var
    return None  # All variables are assigned

def order_domain_values(var, assignment, domains):
    return domains[var]  # Return the domain as it is for simplicity

def is_consistent(var, value, assignment, constraints):
    for constraint in constraints:
        if not constraint(var, value, assignment):
            return False
    return True

# Example constraint function: Different values for A and B
def different_values_constraint(A, B, assignment):
    return assignment.get(A) != assignment.get(B)

# Example usage:
variables = ['A', 'B', 'C']
domains = {
    'A': [1, 2, 3],
    'B': [1, 2],
    'C': [3, 4]
}
constraints = [different_values_constraint]

solution = backtracking_search(variables, domains, constraints)
print(solution)
