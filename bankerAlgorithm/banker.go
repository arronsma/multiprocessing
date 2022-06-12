package main

import ("fmt")

func minusMatrix(m1[][] int, m2[][] int)  {
	
}
func main()  {
	var process, source int
	fmt.Scan(&process, &source)
	fmt.Printf("there are %d process and %d source\n", process, source)

	var max[][] int
	for i:=0 ; i < process; i++ {
		var temp[] int
		for j := 0; j < source; j++{
			var in int
			fmt.Scan(&in)
			temp = append(temp, in)
		}
		max = append(max, temp)
	}
	fmt.Println(max)

}