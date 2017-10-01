mergeSort(int *array, int start, int length, int typeOfData){
	
	if(start < length){ //Divided array into one element
	
	
	int midPoint = start + (length - start) /2; //Midpoint of current size of array
	
	mergeSort(array, start, midPoint, 0); //divide and sort left array
	mergeSort(array, midPoint + 1, length, 0); //divide and sort right array
	
	sort(array, start, midPoint, length); // sort the array
	
	}
	
}

sort(int *array, int start, int midPoint, int length){

	int leftArrayIndex, rightArrayIndex = 0; //indeces for left and right array respectively
	int leftArrayBoundry =  midPoint - start + 1;
	int rightArrayBoundry = length - midPoint;
	
	int left[leftArrayBoundry]; //Left array temp variable
	int right[rightArrayBoundry];	//Right array temp variable
	
	for(leftArrayIndex = 0 ; leftArrayIndex < leftArrayBoundry ; leftArrayIndex++){ //Populate the left array using original array
		left[leftArrayIndex] = array[start + leftArrayIndex];
	}
	
	for(rightArrayIndex = 0 ; rightArrayIndex < rightArrayBoundry ; rightArrayIndex++){ //Populate the right array using original array
		right[rightArrayIndex] = array[midPoint + rightArrayIndex + 1];
	}
	
	leftArrayIndex = 0;
	rightArrayIndex = 0;
	int originalArrayIndex = start; //index for original array
	
	while(leftArrayIndex < leftArrayBoundry && rightArrayIndex < rightArrayBoundry){ //While both right and left arrays still have elements
		
		if(left[leftArrayIndex] <= right[rightArrayIndex]){ //Elements in left array goes before right
			array[originalArrayIndex] = left[leftArrayIndex];
			leftArrayIndex++;
		}
		else{ //Elements in right array goes before right
			array[originalArrayIndex] = right[rightArrayIndex];
			rightArrayIndex++;
		}
		originalArrayIndex++;
	}
	
	while(leftArrayIndex < leftArrayBoundry){ //Left array isn't finished, insert elements into original array
		array[originalArrayIndex] = left[leftArrayIndex];
		originalArrayIndex++;
		leftArrayIndex++;
	}
	
	while(rightArrayIndex < rightArrayBoundry){ //right array isn't finished, insert elements into original array
		array[originalArrayIndex] = right[rightArrayIndex];
		originalArrayIndex++;
		rightArrayIndex++;
	}
	
}
