using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SymbolsLib.Tests
{
    [TestClass]
    public class SymbolsTests
    {
        readonly string[] strings = {
            "Тест",
            "!",
            "/",
            "Тест /!/ тест",
            "Тест!",
            "!/Тест",
            "///!//!!!!/////!!!!!!!!!!!!!!///!/"
        };
        readonly Tuple<int, int>[] results = {
            Tuple.Create(0, 0),
            Tuple.Create(0, 1),
            Tuple.Create(1, 0),
            Tuple.Create(2, 1),
            Tuple.Create(0, 1),
            Tuple.Create(1, 1),
            Tuple.Create(14, 20)
        };

        [TestMethod]
        public void TestNumber1()
        {
            for (int i = 0; i < strings.Length; i++)
            {
                Symbols numbers = new Symbols(strings[i]);
                Tuple<int, int> output = numbers.CheckAndPrint();
                Assert.AreEqual(output.Item1, results[i].Item1);
                Assert.AreEqual(output.Item2, results[i].Item2);
            }
        }

        [TestMethod]
        public void TestNumber2()
        {
            for (int i = 0; i < strings.Length; i++)
            {
                Symbols numbers = new Symbols(null);
                numbers.Check(strings[i]);
                Assert.AreEqual(numbers.countForwardSlash, results[i].Item1);
                Assert.AreEqual(numbers.countExclamationMark, results[i].Item2);
            }
        }
    }
}