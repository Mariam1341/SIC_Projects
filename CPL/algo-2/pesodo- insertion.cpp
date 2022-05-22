for i = 1 to n
       key = arr[i]
       j = i - 1    
	    while j >= 0 and arr[j] > key
           arr[j + 1] = arr[j]
           j = j - 1
        end while
        arr[j + 1] = key
end for

