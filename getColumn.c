char** getColumn(char ***matrix, int column, int length){
	
	
	char **columnresult = (char **)malloc(length * sizeof(char *)); //Allocate the number of rows (of type string) a column has
	
	/*for(i = 0 ; i < r ; i++){
		columnresult[i] = matrix[i][column];
	}*/
	
	for(i = 0 ; i < r ; i++){ //loop through array and allocate the size of each string string from a given row in the column
		columnresult[i] = (char *)malloc(strlen(matrix[i][column])); //element at i allocates size the size of string matrix[i][column]
		strcpy(columnresult[i], matrix[i][column]); //copy the string from the matrix into the string array
	}
	
	
	return columnresult;
}
