using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSML;

namespace Diskreetti02
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] GenMatrix = new int[3, 6] { { 1, 0, 0, 1, 0, 1 }, { 0, 1, 0, 1, 1, 0 }, { 0, 0, 1, 0, 1, 1 } };
            int[,] hMatrix = new int[3, 6] { { 1, 1, 0, 1, 0, 0 }, { 0, 1, 1, 0, 1, 0 }, { 1, 0, 1, 0, 0, 1 } };
            int[] m = new int[] { 1, 0, 1, };
            Dictionary<int[,], int[]> syndromit = new Dictionary<int[,], int[]>();
            generoiSyndromit(GenMatrix, hMatrix, ref syndromit);
     
            Console.WriteLine("Generoija-matriisi:");
            printMatrix2d(GenMatrix);
            Console.WriteLine();
            Console.WriteLine("Tarkistus-matriisi:");
            printMatrix2d(hMatrix);
            Console.WriteLine();
            Console.WriteLine("Sana:");
            printMatrix1d(m);
            int[] r = matrixMultiplication1d2d(m, GenMatrix);
            Console.WriteLine();
            Console.WriteLine("Viesti:");
            printMatrix1d(r);
            Console.WriteLine();
            Console.WriteLine("Viesti virheen kanssa:");
            generoiVirhe(ref r);
            printMatrix1d(r);
            int[,] c = transpose(r);

            Console.WriteLine();
            Console.WriteLine("Tarkistus:");
            int[,] matrixAfterCheck = matrixMultiplication2d2d(hMatrix, c);
            printMatrix2d(matrixAfterCheck);
            foreach (var item in syndromit)
            {
                if (compare2dMatrisies(item.Key, matrixAfterCheck))
                {
                    addMatrisies(ref r, item.Value);
                    Console.WriteLine("Vastaava syndromi: ");
                    printMatrix2d(item.Key);
                    Console.WriteLine("Virhe kohdassa: ");
                    printMatrix1d(item.Value);
                    
                    Console.WriteLine("Matriisi virheen korjauksen jälkeen: ");
                    printMatrix1d(r);
                    break;
                }
                
            }
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="matrix">2D Array to be printed out.</param>
        static void printMatrix2d(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0) ; i++)
            {
                for (int j = 0; j < matrix.GetLength(1) ; j++)
                {
                    Console.Write(matrix[i,j] + "\t");
                }
                Console.WriteLine("\n");
            }
        }
        /// <summary>
        /// Prints 1d array.
        /// </summary>
        /// <param name="matrix">1d matrix</param>
        static void printMatrix1d(int[] matrix)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                Console.Write(matrix[i] + "\t");
            }
        }
        /// <summary>
        /// Matriisitulo kahdella matriisilla, joista endimmäinen on yksiulotteinen.
        /// </summary>
        /// <param name="matrix1"></param>
        /// <param name="matrix2"></param>
        /// <returns></returns>
        static int[] matrixMultiplication1d2d(int[] matrix1, int[,] matrix2)
        {
            int[] result =new int[matrix2.GetLength(1)];

            int rem = 0;
            if(matrix1.Length != matrix2.GetLength(0))
            {
                throw new NotImplementedException("Matriisitulo ei mahdollinen. Vääränkokoiset matriisit");
            }

            for (int i = 0; i < matrix2.GetLength(1); i++)
            {
                rem = 0;
                for (int j = 0; j < matrix1.Length; j++)
                {
                    rem = rem + (matrix1[j] * matrix2[j, i]);
                }
                result[i] = rem % 2;
            }
            return result;
        }

    /// <summary>
    /// Transponoi 1d matriisi.
    /// </summary>
    /// <param name="matrix"></param>
    /// <returns></returns>
        static int[,] transpose(int[] matrix)
        {
            int[,] result = new int[matrix.Length,1];
            for (int i = 0; i < matrix.Length; i++)
            {
                result[i,0] = matrix[i];
            }

            return result;
        }
        /// <summary>
        /// Matriisitulo kahella 2d matriisilla.
        /// </summary>
        /// <param name="matrix1">Matriisi 1</param>
        /// <param name="matrix2">Matriisi 2</param>
        /// <returns></returns>
        static int[,] matrixMultiplication2d2d(int[,] matrix1, int[,] matrix2)
        {
            int[,] result = new int[matrix1.GetLength(0), matrix2.GetLength(1)];
            int rem = 0;

            if(matrix1.GetLength(1) != matrix2.GetLength(0))
            {
                throw new NotImplementedException("Matriisitulo ei mahdollinen. Matriisit väärän kokoisia. ");
            }

            for (int i = 0; i < matrix1.GetLength(0); i++)
            {
                for (int j = 0; j < matrix2.GetLength(1); j++)
                {
                    rem = 0;
                    for (int k = 0; k < matrix1.GetLength(1); k++)
                    {
                        rem += matrix1[i, k] * matrix2[k, j];
                    }
                    result[i, j] = rem % 2;
                }
            }

            return result;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="message"></param>
        static void generoiVirhe(ref int[] message)
        {
            Random rnd = new Random();
            for (int i = 0; i < message.Length; i++)
            {
                int a = rnd.Next(101);
                Console.WriteLine("Random number: " + a);
                if (a > 80)
                {
                    if (message[i] == 1)
                    {
                        message[i] = 0;
                    }
                    else message[i] = 1;
                }
            }
           
        }
        /// <summary>
        /// Generoi syndromit generoija-matrsiisin ja tarkistus-matriisin avulla. Funktio ottaa myös referenssinä dictionaryn, johon
        /// syndromi kandidaattiparit tallennetaan
        /// </summary>
        /// <param name="generoijaMatriisi">Generoijamatriisi</param>
        /// <param name="tarkistusMatriisi">Tarkistusmatriisi</param>
        /// <param name="syndromit">Dictionary referenssinä</param>
        static void generoiSyndromit(int[,] generoijaMatriisi, int[,]tarkistusMatriisi, ref Dictionary<int[,], int[]> syndromit)
        {
            bool canUpdate = false;
            int syndromienLukumäärä = 0;
            int tarvittavatSyndromit = 7;
            int i = 0;
            int[] kandidaatti = new int[] { 0, 0, 0, 0, 0, 0 };
            int[,] syndromi = new int[tarkistusMatriisi.GetLength(0), 1];
            syndromit.Add(matrixMultiplication2d2d(tarkistusMatriisi, transpose(kandidaatti)), kandidaatti);
            while (syndromienLukumäärä < tarvittavatSyndromit)
            {
                canUpdate = false;
                kandidaatti = new int[] { 0, 0, 0, 0, 0, 0 };
                if(Math.Floor((double)i/tarkistusMatriisi.GetLength(1)) > 0)
                {
                    kandidaatti[(int)Math.Floor((double)i / 6) -1] = 1;
                }
                kandidaatti[i%tarkistusMatriisi.GetLength(1)] = 1;
                syndromi = matrixMultiplication2d2d(tarkistusMatriisi, transpose(kandidaatti));
                if (syndromit.ContainsKey(syndromi))
                {
                    i++;
                    continue;
                }
                foreach (var item in syndromit.Keys)
                {
                    if(compare2dMatrisies(item,syndromi))
                    {
                        canUpdate = false;
                        i++;
                        break;
                    }
                    else
                    {
                        canUpdate = true;
                    }
                }
                if(canUpdate)
                {
                    Console.Write("kandidaatti: ");
                    printMatrix1d(kandidaatti);
                    Console.WriteLine("Syndromi");
                    printMatrix2d(syndromi);
                    syndromit.Add(syndromi, kandidaatti);
                    syndromienLukumäärä++;
                    i++;
                }
            }
        }
        /// <summary>
        /// Method for compairing two 2d matrisies.
        /// </summary>
        /// <param name="data1">Matrix 1</param>
        /// <param name="data2">Matrix 2</param>
        /// <returns></returns>
        static bool compare2dMatrisies(int[,] data1, int[,] data2)
        {
            
            bool result = false;
            result = data1.Rank == data2.Rank && Enumerable.Range(0, data1.Rank).All(dimension => data1.GetLength(dimension) == data2.GetLength(dimension)) && data1.Cast<int>().SequenceEqual(data2.Cast<int>());
            return result;
        }
        /// <summary>
        /// Funktio kahden matriisin yhteenlaskuun. Lisää toisen matriisin ensimmäiseen. Ensimmäinen matriisi referenssinä.
        /// </summary>
        /// <param name="matrix1">Matriisi johon lisätään. Referenssinä</param>
        /// <param name="matrix2">Matriisi joka lisätään.</param>
        static void addMatrisies(ref int[] matrix1, int[] matrix2)
        {
            if(matrix1.Length != matrix2.Length)
            {
                throw new NotImplementedException("Matriisien pitää olla yhtä suuria.");
            }
            for (int i = 0; i < matrix1.Length; i++)
            {
                matrix1[i] = (matrix1[i] + matrix2[i]) % 2;
            }
        }
    }

}
