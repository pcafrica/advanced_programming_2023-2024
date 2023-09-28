#!/bin/bash

########################################
# Exercise 3.                          #
########################################

if [ -z "$1" ]
then
    echo "ERROR: No input directory specified!"
    exit 1
fi

if [ ! -d "$1" ]
then
    echo "ERROR: Input argument is not a directory!"
    exit 1
fi

output_directory="${HOME}/backup"

# Create directory, if it does not exist.
mkdir -p ${output_directory}

# Assign input argument to a variable.
input_directory=${1}

# Extract last part of the directory name.
# E.g., if provided "/home/user/Documents",
# the basename is "Documents".
directory_name=$(basename ${input_directory})

# Generate backup directory name.
backup_directory=${directory_name}_$(date +%Y%m%d_%H%M%S)

echo "Copying to backup folder..."
cp -r ${input_directory} ${output_directory}/${backup_directory}

echo "Creating backup archive..."
# Move to the output directory.
pushd ${output_directory} > /dev/null

# Create a tar archive.
# "c" stands for "compress".
# "z" for "gzip" file format.
# "f" for specifying the output "file".
tar czf ${backup_directory}.tar.gz ${backup_directory}

# Go back to the original folder.
popd > /dev/null

echo "Done!"
