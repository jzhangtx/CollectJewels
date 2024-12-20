package main

import "fmt"

type JewelStone struct {
	weight int
	value  int
}

func getTotalValue(stones []JewelStone) int {
	total := 0
	for _, stone := range stones {
		total += stone.value
	}
	return total
}

func getMaxValueHelper(stones []JewelStone, capacity int, start int, maxValue *int, temp *[]JewelStone) {
	if capacity == 0 {
		*maxValue = max(*maxValue, getTotalValue(*temp))
		return
	}

	if capacity > 0 {
		*maxValue = max(*maxValue, getTotalValue(*temp))
	}

	if start == len(stones) || capacity < 0 {
		return
	}

	for i := start; i < len(stones); i++ {
		*temp = append(*temp, stones[i])
		getMaxValueHelper(stones, capacity-stones[i].weight, i+1, maxValue, temp)
		*temp = (*temp)[:len(*temp)-1]
	}
}

func getMaxValue(stones []JewelStone, capacity int) int {
	maxValue := 0
	var temp []JewelStone

	getMaxValueHelper(stones, capacity, 0, &maxValue, &temp)
	return maxValue
}

func main() {
	for {
		fmt.Print("Number of jewels and capacity: ")
		var count, capacity int
		fmt.Scan(&count, &capacity)
		if count == 0 && capacity == 0 {
			break
		}

		jewels := make([]JewelStone, count)
		for i := 0; i < count; i++ {
			fmt.Scan(&jewels[i].weight, &jewels[i].value)
		}

		maxValue := getMaxValue(jewels, capacity)
		fmt.Println(maxValue)
	}
}
