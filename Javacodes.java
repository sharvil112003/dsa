package Assignment_01;
import java.util.*;
public class Merge_Sort {
    static void sort(int[] array,int low,int high){
    	if(low>=high) {
    		return;
    	}
    	int mid=(low+high)/2;
    	sort(array,low,mid);
    	sort(array,mid+1,high);
    	merge(array,low,mid,high);
    }
    static void merge(int[] array,int low,int mid,int high) {
    	int n1=mid-low+1;
    	int n2=high-mid;
    	int left[]=new int[n1];
    	int right[]=new int[n2];
    	for(int i=0;i<n1;i++) {
    		left[i]=array[low+i];
    	}
    	for(int i=0;i<n2;i++) {
    		right[i]=array[mid+i+1];
    	}
    	int i=0;
    	int j=0;
    	while(i!=n1 && j!=n2) {
    		if(left[i]<=right[j]) {
    			array[low+i+j]=left[i];
    			i++;
    		}
    		else {
    			array[low+i+j]=right[j];
    			j++;
    		}
    	}
    	while(i!=n1) {
    		array[low+i+j]=left[i];
    		i++;
    	}
    	while(j!=n2) {
    		array[low+i+j]=right[j];
    		j++;
    	}
    }
    public static void main(String[] args) {
//        int[] array = {1, 6, 7, 23, 2, 8, 0, 3};
//        Merge_Sort.sort(array,0,array.length-1);
//
//        for (int num : array) {
//            System.out.println(num);
//        }
    	int arr[]=new int[500];
		Random random=new Random();
		for(int i=0;i<arr.length;i++) {
			arr[i]=random.nextInt(1000);
		}
        long start=System.nanoTime();
		sort(arr,0,arr.length-1);
		long end=System.nanoTime();
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		long duration=end-start;
		System.out.println("Total Time Taken in Sorting 500 elements : "+duration);
		start=System.nanoTime();
		sort(arr,0,arr.length-1);
		end=System.nanoTime();
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		duration=end-start;
		System.out.println("Total Time Taken in Sorting 500 elements : "+duration);
    }
}

package Assignrmrnt_01_a;
import java.util.*;
public class Quick_Sort {
	static void Quicksort(int[] arr,int low,int high) {
		if(low<high) {
			int partition=sort(arr,low,high);
			Quicksort(arr,low,partition-1);
			Quicksort(arr,partition+1,high);
		}
	}
	static int sort(int[] arr,int low,int high) {
		int pivot=arr[low];
		int i=low;
		int j=high;
		while(i<j) {
			while(arr[i]<=pivot && i<high) {
				i++;
			}
			while(arr[j]>pivot && j>low) {
				j--;
			}
			if(i<j) {
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		int t2=arr[low];
		arr[low]=arr[j];
		arr[j]=t2;
		return j;
	}
	public static void main(String... args) {
		int arr[]=new int[500];
		Random random=new Random();
		for(int i=0;i<arr.length;i++) {
			arr[i]=random.nextInt(1000);
		}
		System.out.println("500 elements Array as an Input :");
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
        long start=System.nanoTime();
		Quicksort(arr,0,arr.length-1);
		long end=System.nanoTime();
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		long duration=end-start;
		System.out.println("Total Time Taken in Sorting 500 elements in Average case: "+duration);
		
		start=System.nanoTime();
		Quicksort(arr,0,arr.length-1);
		end=System.nanoTime();
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		duration=end-start;
		System.out.println("Total Time Taken in Sorting 500 elements in Worst case: "+duration);
	}

}

package Assignment_03;

import java.util.Arrays;
import java.util.Random;

public class p3b {
    public static void main(String[] args) {
//        int[][] initialChromosome = {
//        		{0, 20, 30, 10, 11},
//                {15, 0, 16, 4, 2},
//                {3, 5, 0, 2, 4},
//                {19, 6, 18, 0, 3},
//                {16, 4, 7, 16, 0}
//         };'
    	int[][] initialChromosome= {
    			{Integer.MAX_VALUE,20,30,10,11},
    			{15,Integer.MAX_VALUE,16,4,2},
    			{3,5,Integer.MAX_VALUE,2,4},
    			{19,6,18,Integer.MAX_VALUE,3},
    			{16,4,7,16,Integer.MAX_VALUE}
    	};
        System.out.println("Initial Chromosome:\n" + Arrays.deepToString(initialChromosome));
        int[][] mutatedChromosome = mutateChromosome(initialChromosome);
        System.out.println("\nMutated Chromosome:\n" + Arrays.deepToString(mutatedChromosome));

        int[] path = calculatePath(mutatedChromosome);
        int cost = calculateCost(mutatedChromosome, path);

        System.out.println("\nPath: " + Arrays.toString(path));
        System.out.println("Cost: " + cost);
    }

    private static int[] calculatePath(int[][] chromosome) {
        int[] path = new int[chromosome.length];
        for (int i = 0; i < chromosome.length; i++) {
            path[i] = findIndexOfMin(chromosome[i]);
        }
        return path;
    }

    private static int findIndexOfMin(int[] array) {
        int minIndex = 0;
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    private static int calculateCost(int[][] chromosome, int[] path) {
        int cost = 0;
        for (int i = 0; i < chromosome.length; i++) {
            int fromCity = path[i];
            int toCity = (i + 1) % chromosome.length;  // Wrap around for the last city
            cost += chromosome[fromCity][toCity];
        }
        return cost;
    }
    
    	

    private static int[][] mutateChromosome(int[][] chromosome) {
        // This line creates a copy of the original chromosome. The reason for copying is that we want to modify the order of cities 
    	// in the copy without changing the original order.
        // int[][] mutatedChromosome = Arrays.stream(chromosome).map(int[]::clone).toArray(int[][]::new);
        int[][] mutatedChromosome = Arrays.copyOf(chromosome, chromosome.length);

        // The function randomly selects two indices (index1 and index2) in the range of the number of cities in the chromosome. It ensures that index2 is different from index1 to make a meaningful swap.
        Random rand = new Random();
        int index1 =rand.nextInt(chromosome.length);
        int index2;
        
        do {
            index2 = rand.nextInt(chromosome.length);
        } while (index1 == index2);

        // This loop goes through each row in the chromosome and swaps the values at index1 and index2. It's like the robot (or the program) deciding to change the order of two cities in its plan for each possible route.
        for (int i = 0; i < chromosome.length; i++) {
            int temp = mutatedChromosome[i][index1];
            mutatedChromosome[i][index1] = mutatedChromosome[i][index2];
            mutatedChromosome[i][index2] = temp;
        }
        // Finally, the function returns the mutated chromosome, which represents a new order of cities for the robot to visit.
        return mutatedChromosome;
    }
}


// This program is like a game for a robot that wants to visit different cities. Each city is like a friend's house, and the robot wants to find the shortest path to visit all of them and come back home.

package KnapSack;

import java.util.Scanner;

public class KP_64 {
	
	public static void main(String... args) {
		int[] Weight= {2,4,6,9};
		int[] Profit= {10,10,12,18};
		int max_wt=15;
		int n=4;
		
		int T[][]=new int[n+1][max_wt+1];
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=max_wt;j++) {
				try {
				T[i][j]=Math.max(T[i-1][j], Profit[i-1]+T[i-1][j-Weight[i-1]]);
				} catch(Exception ArrayIndexOutOfBoundsException){
				T[i][j]=T[i-1][j];
				}
			}
		}
		
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=max_wt;j++) {
				System.out.print(T[i][j]+"  ");
			}
			System.out.println();
		}
		System.out.print("Max Profit with weigt limit "+max_wt+" is :"+T[n][max_wt]);
	}

}


package Assignment_06;
import java.util.ArrayList;

public class N_Queens {
    static boolean issafe(int col, int row, String[][] board) {
        for (int i = 0; i < board.length; i++) {
            if (board[i][row].equals("Q")) {
                return false;
            }
        }

        for (int i = 0; i < board.length; i++) {
            if (board[col][i].equals("Q")) {
                return false;
            }
        }

        int r = row;
        int c = col;
        while (c >= 0 && r >= 0) {
            if (board[c][r].equals("Q")) {
                return false;
            }
            c--;
            r--;
        }
        r = row;
        c = col;
        while (c >= 0 && r != board.length) {
            if (board[c][r].equals("Q")) {
                return false;
            }
            c--;
            r++;
        }

        r = row;
        c = col;
        while (r >= 0 && c != board.length) {
            if (board[c][r].equals("Q")) {
                return false;
            }
            r--;
            c++;
        }

        r = row;
        c = col;
        while (c != board.length && r != board.length) {
            if (board[c][r].equals("Q")) {
                return false;
            }
            c++;
            r++;
        }

        return true;
    }

    static void add_ans(String[][] board, ArrayList<ArrayList<String>> Al) {
        ArrayList<String> temp = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            String ans = "";
            for (int j = 0; j < board.length; j++) {
                if (board[i][j].equals("Q")) {
                    ans += "Q";
                } else {
                    ans += "*";
                }
            }
            temp.add(ans);
        }
        Al.add(temp);
    }

    static void build(ArrayList<ArrayList<String>> Al, String[][] board, int col) {
        if (col == board.length) {
            add_ans(board, Al);
            return;
        }
        for (int i = 0; i < board.length; i++) {
            if (issafe(col, i, board)) {
                board[col][i] = "Q";
                build(Al, board, col + 1);
                board[col][i] = "";
            }
        }
    }

    public static void main(String... args) {
        int n = 5;
        ArrayList<ArrayList<String>> Al = new ArrayList<>();
        String[][] board = new String[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = ""; // Initialize with an empty string
            }
        }
        build(Al, board, 0);

        // Print each solution on a new line
        for (ArrayList<String> solution : Al) {
            System.out.println(solution);
        }
    }
}

import java.util.concurrent.Semaphore;

class Philosopher extends Thread {
    private Semaphore leftChopstick;
    private Semaphore rightChopstick;

    public Philosopher(Semaphore leftChopstick, Semaphore rightChopstick) {
        this.leftChopstick = leftChopstick;
        this.rightChopstick = rightChopstick;
    }

    private void think() throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " is thinking");
        Thread.sleep((long) (Math.random() * 1000));
    }

    private void eat() throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " is eating");
        Thread.sleep((long) (Math.random() * 1000));
    }

    @Override
    public void run() {
        try {
            while (true) {
                think();

                leftChopstick.acquire();
                System.out.println(Thread.currentThread().getName() + " picked up left chopstick");

                rightChopstick.acquire();
                System.out.println(Thread.currentThread().getName() + " picked up right chopstick");

                eat();

                leftChopstick.release();
                System.out.println(Thread.currentThread().getName() + " released left chopstick");

                rightChopstick.release();`
                System.out.println(Thread.currentThread().getName() + " released right chopstick");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class DiningPhilosophers {
    public static void main(String[] args) {
        int numPhilosophers = 5;
        Semaphore[] chopsticks = new Semaphore[numPhilosophers];

        for (int i = 0; i < numPhilosophers; i++) {
            chopsticks[i] = new Semaphore(1);
        }

        Philosopher[] philosophers = new Philosopher[numPhilosophers];
        for (int i = 0; i < numPhilosophers; i++) {
            philosophers[i] = new Philosopher(chopsticks[i], chopsticks[(i + 1) % numPhilosophers]);
            philosophers[i].start();
        }
    }
}



package Assignment_07;
import java.util.*;

class TSP {
    static int[][] graph; // Adjacency matrix representing distances between cities
    static int minCost = Integer.MAX_VALUE;
    static int[] minPath;

    // Function to solve TSP using Branch and Bound
    static void solveTSP(int[][] adjacencyMatrix) {
        int n = adjacencyMatrix.length;
        graph = adjacencyMatrix;
        boolean[] visited = new boolean[n];
        int[] path = new int[n];
        Arrays.fill(path, -1);
        int currCost = 0;

        // Start from vertex 0
        path[0] = 0;
        visited[0] = true;

        // Call helper function to find minimum cost path
        branchAndBound(1, currCost, path, visited, n);
        
        // Output the minimum cost path
        System.out.println("Minimum Cost: " + minCost);
        System.out.println("Path: " + Arrays.toString(minPath));
    }

    // Helper function implementing Branch and Bound
    static void branchAndBound(int level, int currCost, int[] path, boolean[] visited, int n) {
        if (level == n) {
            if (graph[path[level - 1]][path[0]] != 0) {
                int totalCost = currCost + graph[path[level - 1]][path[0]];
                if (totalCost < minCost) {
                    minCost = totalCost;
                    minPath = path.clone();
                }
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[path[level - 1]][i] != 0) {
                visited[i] = true;
                path[level] = i;
                branchAndBound(level + 1, currCost + graph[path[level - 1]][i], path, visited, n);
                visited[i] = false;
                path[level] = -1;
            }
        }
    }

    public static void main(String[] args) {
        int[][] distances = {
            {0, 20, 30, 10, 11},
            {15, 0, 16, 4, 2},
            {3, 5, 0, 2, 4},
            {19, 6, 18, 0, 3},
            {16, 4, 7, 16, 0}
        };

        solveTSP(distances);
    }
}


(II)	 package Assignment_07_b;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class TSP_b {

    static class Individual {
        int[] chromosome;
        int fitness;

        Individual(int[] chromosome) {
            this.chromosome = chromosome;
            this.fitness = calculateFitness();
        }

        int calculateFitness() {
            int totalDistance = 0;
            for (int i = 0; i < chromosome.length - 1; i++) {
                totalDistance += distances[chromosome[i]][chromosome[i + 1]];
            }
            totalDistance += distances[chromosome[chromosome.length - 1]][chromosome[0]]; // Return to the starting city
            return totalDistance;
        }
    }

    private static int[][] distances;

    TSP_b(int[][] distances) {
        this.distances = distances;
    }

    Individual crossover(Individual parent1, Individual parent2) {
        int[] childChromosome = new int[parent1.chromosome.length];
        Arrays.fill(childChromosome, -1);

        int startPos = (int) (Math.random() * parent1.chromosome.length);
        int endPos = (int) (Math.random() * parent1.chromosome.length);

        for (int i = 0; i < parent1.chromosome.length; i++) {
            if (startPos < endPos && i >= startPos && i <= endPos) {
                childChromosome[i] = parent1.chromosome[i];
            } else if (startPos > endPos && !(i <= startPos && i >= endPos)) {
                childChromosome[i] = parent1.chromosome[i];
            }
        }

        for (int i = 0; i < parent2.chromosome.length; i++) {
            if (!contains(childChromosome, parent2.chromosome[i])) {
                for (int j = 0; j < childChromosome.length; j++) {
                    if (childChromosome[j] == -1) {
                        childChromosome[j] = parent2.chromosome[i];
                        break;
                    }
                }
            }
        }

        return new Individual(childChromosome);
    }

    void mutate(Individual individual) {
        int mutationPoint1 = (int) (Math.random() * individual.chromosome.length);
        int mutationPoint2 = (int) (Math.random() * individual.chromosome.length);

        int temp = individual.chromosome[mutationPoint1];
        individual.chromosome[mutationPoint1] = individual.chromosome[mutationPoint2];
        individual.chromosome[mutationPoint2] = temp;
    }

    Individual selectParent(List<Individual> population) {
        Collections.shuffle(population);
        return population.get(0).fitness < population.get(1).fitness ? population.get(0) : population.get(1);
    }

    boolean contains(int[] arr, int key) {
        for (int i : arr) {
            if (i == key) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] distances = {
                {0, 20, 30, 10, 11},
                {15, 0, 16, 4, 2},
                {3, 5, 0, 2, 4},
                {19, 6, 18, 0, 3},
                {16, 4, 7, 16, 0}
        };

        TSP_b ga = new TSP_b(distances);
        List<Individual> population = ga.initializePopulation(50);

        for (int generation = 0; generation < 1000; generation++) {
            population = ga.evolvePopulation(population);
            System.out.println("Generation " + generation + ": Minimum Distance = " + ga.getFittest(population).fitness);
        }

        Individual bestIndividual = ga.getFittest(population);
        System.out.println("Best Path: " + Arrays.toString(bestIndividual.chromosome));
        System.out.println("Best Distance: " + bestIndividual.fitness);
    }

    List<Individual> initializePopulation(int populationSize) {
        List<Individual> population = new ArrayList<>();
        for (int i = 0; i < populationSize; i++) {
            population.add(generateIndividual());
        }
        return population;
    }

    Individual generateIndividual() {
        int[] chromosome = new int[distances.length];
        for (int i = 0; i < distances.length; i++) {
            chromosome[i] = i;
        }
        shuffleArray(chromosome);
        return new Individual(chromosome);
    }

    List<Individual> evolvePopulation(List<Individual> population) {
        List<Individual> newPopulation = new ArrayList<>();
        for (int i = 0; i < population.size(); i++) {
            Individual parent1 = selectParent(population);
            Individual parent2 = selectParent(population);
            Individual child = crossover(parent1, parent2);
            if (Math.random() < 0.01) {
                mutate(child);
            }
            newPopulation.add(child);
        }
        return newPopulation;
    }

    Individual getFittest(List<Individual> population) {
        Individual fittest = population.get(0);
        for (Individual individual : population) {
            if (individual.fitness < fittest.fitness) {
                fittest = individual;
            }
        }
        return fittest;
    }

    void shuffleArray(int[] array) {
        Random rnd = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);
            int temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
                            }
