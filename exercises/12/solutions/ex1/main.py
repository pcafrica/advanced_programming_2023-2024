import data_processor as dp

input1 = [2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75]
input2 = [0.73, -0.45, 0.12, 0.88, -0.67, 0.34, -0.92]

dp1 = dp.DataProcessor(input1)
dp2 = dp.DataProcessor(input2)

print(f"dp1: {dp1}")
print(f"dp2: {dp2}")
print(f"Number of instances: {dp1.get_n_instances()}")
print(f"Minimum value of dp1: {dp1.min()}")
print(f"Maximum value of dp1: {dp1.max()}")
print(f"Mean of dp1: {dp1.compute_mean()}")
print(f"Standard deviation of dp1: {dp1.compute_std_dev()}")

dp3 = dp1 + dp2
print(f"dp3: {dp3}")
print(f"dp3[3]: {dp3[3]}")
dp3[3] = 0.0
print(f"dp3[3]: {dp3[3]}")

print(f"Correlation between dp1 and dp2: {dp.compute_correlation(dp1, dp2)}")

del dp2
print(f"Number of instances: {dp1.get_n_instances()}")
