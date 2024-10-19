import pandas as pd
import numpy as np

# Set the number of assets and data points per asset
num_assets = 1000
num_values_per_asset = 10

# Initialize a list to hold each row of data
data = []

# Generate data for each asset
for i in range(num_assets):
    # Generate random values
    values = np.random.uniform(1, 5, size=num_values_per_asset)
    # Sort the values in ascending order
    sorted_values = np.sort(values)
    # Create the row with asset label and values
    row = [f'Asset_{i + 1}'] + sorted_values.tolist()
    data.append(row)

# Create a DataFrame from the generated data
df = pd.DataFrame(data)

# Save the data to a CSV file
output_file_path = 'data/covariance_large.csv'
df.to_csv(output_file_path, index=False, header=False)

print(f"Data saved to {output_file_path}")
