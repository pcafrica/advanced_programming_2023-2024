class DataAnalyzer:
    """
    Class for analyzing data in a DataFrame.

    Parameters:
    - result_column: str
        Name of the column containing the result values.
    """
    def __init__(self, result_column):
        self.result_column = result_column

    def analyze_data(self, df):
        """
        Analyze the data in the DataFrame by calculating the mean
        and maximum values of the specified result_column.

        Parameters:
        - df: pd.DataFrame
            Input DataFrame containing data.

        Returns:
        - tuple
            A tuple containing mean and maximum values.
        """
        mean_val = df[self.result_column].mean()
        max_val = df[self.result_column].max()
        return mean_val, max_val
