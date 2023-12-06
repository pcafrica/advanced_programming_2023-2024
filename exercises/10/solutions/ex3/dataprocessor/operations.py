import pandas as pd

def process_data(df, column1, column2, result_column):
    """
    Perform data processing by adding values from column1 and column2,
    and store the result in the specified result_column.

    Parameters:
    - df: pd.DataFrame
        Input DataFrame containing data.
    - column1: str
        Name of the first column.
    - column2: str
        Name of the second column.
    - result_column: str
        Name of the column to store the result.

    Returns:
    - pd.DataFrame
        DataFrame with the processed data.
    """
    df[result_column] = df[column1] + df[column2]
    return df

def additional_operation(df, column1, column2, additional_column1, additional_column2):
    """
    Perform additional operations on the DataFrame by multiplying column1 and column2
    and storing the result in additional_column1, and dividing column1 by column2
    and storing the result in additional_column2.

    Parameters:
    - df: pd.DataFrame
        Input DataFrame containing data.
    - column1: str
        Name of the first column.
    - column2: str
        Name of the second column.
    - additional_column1: str
        Name of the column to store the multiplication result.
    - additional_column2: str
        Name of the column to store the division result.

    Returns:
    - pd.DataFrame
        DataFrame with the additional operations applied.
    """
    df[additional_column1] = df[column1] * df[column2]
    df[additional_column2] = df[column1] / df[column2]
    return df
