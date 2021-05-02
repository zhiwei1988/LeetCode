class Solution {
	public:
		int videoStitching(vector<vector<int>>& clips, int T) {
			std::sort(begin(clips), end(clips), [] (auto &left, auto &right) -> bool {
					if (left[0] == right[0]) {
					return right[1] < left[1];
					}

					return left[0] < right[0];
					});

			int curEnd = 0;
			int startIndex = 0;
			int clipCnt = 0;
			while (startIndex < clips.size()) {
				int clipIndex = getNextClipIndex(clips, startIndex, curEnd);
				if (clipIndex == -1) {
					break;
				}

				curEnd = clips[clipIndex][1];
				clipCnt++;

				if (curEnd >= T) {
					break;
				}

				startIndex = clipIndex + 1;
			}

			if (curEnd < T) {
				return -1;
			}

			return clipCnt;
		}

		int getNextClipIndex(vector<vector<int>>& clips, int startIndex, int curEnd) {
			int nextIndex = -1;
			int maxEnd = -1;
			for (int i = startIndex; i < clips.size(); i++) {
				if (clips[i][0] <= curEnd) {
					if (clips[i][1] > maxEnd) {
						nextIndex = i;
						maxEnd = clips[i][1];
					}
				} else {
					break;
				}
			}
			return nextIndex;
		}
};
