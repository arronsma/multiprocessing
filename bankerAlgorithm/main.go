package main

import (
	"fmt"
	"strconv"
)

// if all element in v1 is less or equal than v2
func vecAllLe(v1, v2 [] int) (bool) { 
	for i := range(v1){
		if (v1[i] > v2[i]){
			return false
		}
	}
	return true
}

func vecAdd(v1, v2 [] int, v3 *[] int){
	for i := range(v1){
		(*v3)[i] = v1[i] + v2[i]
	}
}

func isSafe(sourceVec [] int, max, allocation, need[][] int, process, source int)(bool)  {
	finish := make([] bool, 5)
	res := process 
	work := make([] int, source)
	copy(work, sourceVec)
	var order [] int
	for i := range(finish){
		finish[i] = false
	}

	for res != 0{
		getOne := false
		for i := range(finish){
			if (finish[i] == true){
				continue
			}

			if (vecAllLe(need[i], work)){
				order = append(order, i)
				finish[i] = true
				vecAdd(work, allocation[i], &work)
				res -= 1
				getOne = true
			}
		}

		if (getOne == false){
			return false
		}
	}

	return true
}

func vectorRead(vec* [] int, l int){
	for i := 0; i < l; i++{
		var t int
		fmt.Scan(&t)
		(*vec) = append((*vec), t)
	}
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

	fmt.Printf("please enter source vector")
	var sourceVector [] int
	vectorRead(&sourceVector, source)
	fmt.Println(sourceVector)

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

	fmt.Printf("current status is safe? %s\n", strconv.FormatBool(isSafe(sourceVector, max, allocation, need,process, source)))

	

}