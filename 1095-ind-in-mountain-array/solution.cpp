/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int peak = findThePeak(mountainArr, left, right);

        int result = binarySearchLeft(mountainArr, left, peak, target);
        if (result != -1) {
            return result;
        }

        result = binarySearchRight(mountainArr, peak, right, target);
        if (result != -1) {
            return result;
        }

        return -1;
    }

private:
    int findThePeak(MountainArray &mountainArr, int left, int right) {
        int mid = (left + right) / 2;
        int midValue = mountainArr.get(mid);
        int midLeft = mountainArr.get(mid-1);
        int midRight = mountainArr.get(mid+1);
        if (midValue > midLeft && midValue > midRight) {
            return mid;
        } else if (midValue > midLeft && midValue < midRight) {
            return findThePeak(mountainArr, mid, right);
        } else {
            return findThePeak(mountainArr, left, mid);
        }
    }

    int binarySearchLeft(MountainArray &mountainArr, int left, int right, int target) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        int midValue = mountainArr.get(mid);
        if (midValue == target) {
            return mid;
        } else if (midValue < target) {
            return binarySearchLeft(mountainArr, mid+1, right, target);
        } else {
            return binarySearchLeft(mountainArr, left, mid-1, target);
        }
    }

    int binarySearchRight(MountainArray &mountainArr, int left, int right, int target) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        int midValue = mountainArr.get(mid);
        if (midValue == target) {
            return mid;
        } else if (midValue > target) {
            return binarySearchRight(mountainArr, mid+1, right, target);
        } else {
            return binarySearchRight(mountainArr, left, mid-1, target);
        }
    }
};
