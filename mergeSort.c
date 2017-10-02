mergeSort(char ***matrix, char **columnArray, short *rowIndeces, int start, int length, int typeOfData){
	
	//if type of data = 0, its string
	//if type of data = 1, its numeric
	//if type of data = 2, its date/time
	
	if(start < length){ //Divided array into one element
	
	
	int midPoint = start + (length - start) /2; //Midpoint of current size of array
	
	mergeSort(matrix, columnArray, rowIndeces, start, midPoint, typeOfData); //divide and sort left array
	mergeSort(matrix, columnArray, rowIndeces, midPoint + 1, length, typeOfData); //divide and sort right array
	
	sort(matrix, columnArray, rowIndeces, start, midPoint, length, typeOfData); // sort the array
	
	}
	
}

sort(char ***matrix, char **columnArray, short *rowIndeces, int start, int midPoint, int length, int typeOfData){

	int leftArrayIndex, rightArrayIndex = 0; //indeces for left and right array respectively
	int leftArrayBoundry =  midPoint - start + 1;
	int rightArrayBoundry = length - midPoint;
	
	char **left = (char**)malloc(leftArrayBoundry * sizeof(char *)); //Left array temp variable
	char **right = (char **)malloc(rightArrayBoundry * sizeof(char *));	//Right array temp variable
	
	for(leftArrayIndex = 0 ; leftArrayIndex < leftArrayBoundry ; leftArrayIndex++){ //Populate the left array using original array
		left[leftArrayIndex] = columnArray[start + leftArrayIndex];
	}
	
	for(rightArrayIndex = 0 ; rightArrayIndex < rightArrayBoundry ; rightArrayIndex++){ //Populate the right array using original array
		right[rightArrayIndex] = columnArray[midPoint + rightArrayIndex + 1];
	}
	
	leftArrayIndex = 0;
	rightArrayIndex = 0;
	int originalArrayIndex = start; //index for original array
	
	while(leftArrayIndex < leftArrayBoundry && rightArrayIndex < rightArrayBoundry){ //While both right and left arrays still have elements
		
		int result = 0; // the result of two strings or numerics being compared
		double leftnum = atoi(left[leftArrayIndex]);
		double rightnum = atoi(right[rightArrayIndex]);
		
		if(typeOfData){ // comparing two numerics in the strings
			if(leftnum <= rightnum){
				result = -1;
			}
			else{
				result = 1;
			}
		}
		
		else{
			result = strcasecmp(left[leftArrayIndex], right[rightArrayIndex]); // compares the two strings
		}
		
		if(result == 0){ // both strings are equal, take the left subarray as precedence
			columnArray[originalArrayIndex] = left[leftArrayIndex];
			rowIndeces[originalArrayIndex] = leftArrayIndex;
			leftArrayIndex++;
		}
		
		else if(result < 0){ // left arrays has string that comes before the right array string
			columnArray[originalArrayIndex] = left[leftArrayIndex];
			rowIndeces[originalArrayIndex] = leftArrayIndex;
			leftArrayIndex++;
		}
		
		else{ // right array has string that comes before the left array string
			columnArray[originalArrayIndex] = right[rightArrayIndex];
			rowIndeces[originalArrayIndex] = rightArrayIndex;
			rightArrayIndex++;
		}
		originalArrayIndex++;
	}
	
	while(leftArrayIndex < leftArrayBoundry){ //Left array isn't finished, insert elements into original array
		columnArray[originalArrayIndex] = left[leftArrayIndex];
		rowIndeces[originalArrayIndex] = leftArrayIndex;
		originalArrayIndex++;
		leftArrayIndex++;
	}
	
	while(rightArrayIndex < rightArrayBoundry){ //right array isn't finished, insert elements into original array
		columnArray[originalArrayIndex] = right[rightArrayIndex];
		rowIndeces[originalArrayIndex] = rightArrayIndex;
		originalArrayIndex++;
		rightArrayIndex++;
	}
	
	free(left);
	free(right);
	
}
