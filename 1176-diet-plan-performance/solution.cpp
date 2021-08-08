class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int totalCalories = 0;
        int totalScore = 0;
        for (int i = 0; i < k; i++) {
            totalCalories += calories[i];
        }

        if (totalCalories > upper) {
            totalScore++;
        } else if (totalCalories < lower) {
            totalScore--;
        }
        
        for (int i = k; i < calories.size(); i++) {
            totalCalories += calories[i];
            totalCalories -= calories[i-k];

            if (totalCalories > upper) {
                totalScore += 1;
            } else if (totalCalories < lower) {
                totalScore -= 1;
            }
        }

        return totalScore;
    }
};