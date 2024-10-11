import heapq
class Solution(object):
    def smallestChair(self, times, targetFriend):
        """
        :type times: List[List[int]]
        :type targetFriend: int
        :rtype: int
        """
        targetTime = times[targetFriend][0]
        times.sort()
       

        leave = dict()
        mx = max(max(time) for time in times)
        mn = min(min(time) for time in times)
        heap = []
        for i in range(mx+1):
            heapq.heappush(heap,i)

        idx = 0
        leave = dict()
        for i in range(mn,mx+1):
            if i in leave:
                for val in leave[i]:
                    heapq.heappush(heap,val)
            if(times[idx][0] == i):
                temp = heapq.heappop(heap)
                if i == targetTime:
                    return temp
                if times[idx][1] not in leave:
                    leave[times[idx][1]] = list()
                leave[times[idx][1]].append(temp)
                idx+=1

        return 0


