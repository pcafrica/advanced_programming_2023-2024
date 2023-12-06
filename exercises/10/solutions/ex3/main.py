from dataprocessor import process_data, additional_operation, DataAnalyzer, pd

# Configuration settings.
data_config = {
    'column1': 'A',
    'column2': 'B',
    'result_column': 'Result',
    'additional_column1': 'Additional1',
    'additional_column2': 'Additional2',
}

data = pd.DataFrame({
    data_config['column1']: [1, 2, 3, 4],
    data_config['column2']: [5, 6, 7, 8],
})

def main():
    # Process data.
    processed_data = process_data(data, data_config['column1'], data_config['column2'], data_config['result_column'])

    # Analyze data.
    analyzer = DataAnalyzer(data_config['result_column'])
    mean, max_val = analyzer.analyze_data(processed_data)
    print(f"Mean: {mean}, Max: {max_val}")

    # Additional operation.
    additional_data = additional_operation(processed_data, data_config['column1'], data_config['column2'],
                                           data_config['additional_column1'], data_config['additional_column2'])

    print("Final processed data:")
    print(additional_data)

if __name__ == "__main__":
    main()
