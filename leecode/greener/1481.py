from collections import Counter
class Solution(object):
     def findLeastNumOfUniqueInts(self,arr, k):
        count = Counter(arr)
        freq_list = sorted(count.values())
        distinct = len(freq_list) 
        for freq in freq_list:
            if k >= freq:
                k -= freq         
                distinct -= 1     
            else:
                break            
        return distinct
            