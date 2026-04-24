// Last updated: 4/24/2026, 10:17:37 PM
func twoSum(nums []int, target int) []int {
    type pair struct {
        val, idx int
    }
    
    pairs := make([]pair, len(nums))
    for i, v := range nums {
        pairs[i] = pair{v, i}
    }
    
    sort.Slice(pairs, func(i, j int) bool {
        return pairs[i].val < pairs[j].val
    })
    
    i, j := 0, len(pairs)-1
    for i < j {
        sum := pairs[i].val + pairs[j].val
        if sum == target {
            return []int{pairs[i].idx, pairs[j].idx}
        } else if sum < target {
            i++
        } else {
            j--
        }
    }
    return nil
}