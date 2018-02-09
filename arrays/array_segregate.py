def evenodd(arr):
	start_index , last_index=0,len(arr) -1
	s_flag, l_flag = True, True 
	for i in range(0, len(arr)):
		if start_index > last_index:
			break
		if arr[start_index] % 2 == 0 and s_flag:
			s_flag = False
		if s_flag:
			start_index +=1
		if arr[last_index] % 2 == 1 and l_flag:
			l_flag = False
		if l_flag:
			last_index -=1
		if not s_flag and not l_flag:
			temp = arr[start_index]
			arr[start_index] = arr[last_index]
			arr[last_index] = temp
			s_flag, l_flag= True, True



arr = [23,81,86,73,44,32,17,19,20]
evenodd(arr)
print("array after segregation")
for i in range(0, len(arr)):
	print(arr[i])