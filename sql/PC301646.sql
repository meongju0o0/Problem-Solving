select count(*) as count
from ecoli_data
where (2 & genotype = 0) and ((5 & genotype) in (1, 4, 5));