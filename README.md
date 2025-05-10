## Nussinov Algorithm (DP)
### Constraints
no sharp turns: (b_i, b_j), i < j -4 <br/>
no crossing over: (b_i, b_j), (b_k, b_l), i < j < k < l, or k < i < j < l


### Recurrence formula
```
OPT(i, j) is max # of pairs of b_i, .. b_j
OPT(i, j) = max {
    OPT(i, j-1), --> (i,j) isn't a valid pair
    max_t {1 + OPT(i,t-1) + OPT(t+1, j-1)} --> i <= t < j-4 (hairpin structure where t is some break pt)
}
```

### Usage
Run `make` </br>
Edit `sequence.txt` with valid sequence </br>
Run `./main` for maximum base pairings </br>

### Sources
https://bio.libretexts.org/Bookshelves/Computational_Biology/Book%3A_Computational_Biology_-_Genomes_Networks_and_Evolution_(Kellis_et_al.)/10%3A_RNA_Folding/10.04%3A_RNA_Structure <br />
https://math.mit.edu/classes/18.417/Slides/rna-prediction-nussinov.pdf <br />
https://www.youtube.com/watch?v=rE2Q_ewhMfY&ab_channel=LuayNakhleh <br />
