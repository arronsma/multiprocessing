package main

import ("fmt")

func minusMatrix(m1[][] int, m2[][] int)  {
	
}

func matrixRead(matrix* [][] int, r,c int)  {
	for i:=0 ; i < r; i++ {
		var temp[] int
		for j := 0; j < c; j++{
			var in int
			fmt.Scan(&in)
			temp = append(temp, in)
		}
		*matrix = append(*matrix, temp)
	}
}

func matrixMinus(m1 [][] int, m2[][] int, res* [][] int, m, n int){
	*res = make([][]int, m)
	for i := 0; i < m; i++{
		(*res)[i] = make([]int, n)
		for j := 0; j < n; j++{
			(*res)[i][j] = m1[i][j] - m2[i][j]
		}
	}
}

func main()  {
	var process, source int
	fmt.Printf("please enter process number and source number\n")
	fmt.Scan(&process, &source)
	fmt.Printf("there are %d process and %d source\n", process, source)

	fmt.Printf("please enter max matrix:\n")
	var max[][] int
	matrixRead(&max, process, source)
	fmt.Println(max)

	fmt.Printf("please enter allocation matrix:\n")
	var allocation [][] int
	matrixRead(&allocation, process, source)
	fmt.Println(allocation)

	var need[][] int
	matrixMinus(max, allocation, &need, process, source)
	fmt.Println(need)

	

}