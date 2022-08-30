int idx = lower_bound(queryScores.begin(),queryScores.end(),score) - queryScores.begin();
            answer.push_back(queryScores.size() - idx);