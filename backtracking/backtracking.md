🔑 Backtracking Index & Loop — Master Summary
1️⃣ Two roles — never mix them
For-loop (i)
Decides WHAT element to try next
Moves horizontally across choices
Handles duplicate skipping
Always uses nums[i]
Recursion index (start)

Decides WHICH elements are allowed
Moves vertically (depth)
Controls reuse vs no-reuse
Loop chooses the element.
Recursion decides the rules.

2️⃣ The Golden Rule (this kills most bugs)
After choosing nums[i], ask:
❓ Can I reuse this element?
Problem	Recursive call
Subsets II	dfs(i + 1)
Combination Sum	dfs(i)
Combination Sum II	dfs(i + 1)
📌 Reuse allowed → stay at i
📌 Reuse forbidden → move to i + 1

3️⃣ What index REALLY means
❌ Wrong thinking
“index is my position in the array”
✅ Correct thinking
“index is my permission boundary”
It answers:
“From where am I allowed to choose next?”

4️⃣ Why include/exclude fails you here
Include/exclude works for:
Binary decisions
Each index used once
Combination problems are:
Multi-choice
Depth-controlled
For-loop driven

📌 Use for-loop backtracking for combinations.

5️⃣ Duplicate skipping (only when needed)
Only when input may contain duplicates and reuse is forbidden:
if (i > start && nums[i] == nums[i - 1]) continue;
“Same value”
“Same depth”
“Skip it”

6️⃣ Minimal universal template (mental model)
dfs(start):
    record current if valid

    for i from start to n:
        choose nums[i]
        dfs(next_start)
        unchoose
Where:
next_start = i → reuse allowed
next_start = i + 1 → reuse forbidden

7️⃣ One-sentence mantra (memorize)
Loop picks the number.
Recursion enforces the rules.
Reuse decides i vs i + 1.

8️⃣ Self-check before coding (MANDATORY)
Before typing code, answer:
Can elements repeat? → i or i+1?
Do duplicates exist? → skip rule needed?
Does order matter? → forward only?