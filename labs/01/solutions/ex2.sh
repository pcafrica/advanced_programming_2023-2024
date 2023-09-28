#!/bin/bash

########################################
# Exercise 2.                          #
########################################

filename=HPC_2k.log_structured.csv
wget https://raw.githubusercontent.com/logpai/loghub/master/HPC/${filename}


########################################
# 1.                                   #
########################################

# Print the third column in a comma-separated file.
# Discard the first row, as it only contains header information.
unique_nodes=$(tail -n +1 ${filename} | cut -d, -f3 | sort | uniq)

echo "Number of unique nodes: $(echo "${unique_nodes}" | wc -l)"


########################################
# 2.                                   #
########################################

echo "${unique_nodes}" > nodes.log


########################################
# 3.                                   #
########################################

echo "Number of \"unavailable\" events reported: $(grep "E13" ${filename} | wc -l)"


########################################
# 4.                                   #
########################################

echo \
"Number of unique nodes that have reported events E32 or E33: \
$(grep "E32\|E33" ${filename} | cut -d, -f3 | sort | uniq | wc -l)"


########################################
# 5.                                   #
########################################

echo \
"Number of times that node \"gige7\" has reported event E15: \
$(grep "gige7.*E15" ${filename} | wc -l)"


########################################
# 6.                                   #
########################################

# Be sure not to include node-20, node-21, ..., node-200, ..., node-2**!
echo "Number of reports for \"nodes-2\": $(grep "node-2," ${filename} | wc -l)"
