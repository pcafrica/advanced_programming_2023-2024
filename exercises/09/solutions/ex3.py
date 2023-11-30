#!/usr/bin/env python3

def symmetric_difference(set1, set2):
    """
    Compute the symmetric difference between two sets manually.
    
    Parameters
    ----------
    - set1 : set
             the first set
    - set2 : set
             the second set
    
    Returns
    -------
    set
        the symmetric difference between set1 and set2

    Examples
    --------
    >>> symmetric_difference({1, 2, 3, 4}, {3, 4, 5, 6})
    {1, 2, 5, 6}
    """
    
    # Elements in set1 but not in set2.
    diff1 = set1.difference(set2)
    
    # Elements in set2 but not in set1.
    diff2 = set2.difference(set1)
    
    # Symmetric difference is the union of the two differences.
    symmetric_diff = diff1.union(diff2)
    
    return symmetric_diff

# Example usage:
set_a = {1, 2, 3, 4}
set_b = {3, 4, 5, 6}

result_manual = symmetric_difference(set_a, set_b)
print("Symmetric difference (manual):", result_manual)
print("Symmetric difference (built-in):", set_a.symmetric_difference(set_b))
