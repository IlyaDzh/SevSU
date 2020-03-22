using System.IO;

public static class AVLTreeExtensions
{
    static string result = "";
    private static void PrintNode<T>(T rootValue, T childValue)
    {
        result += $"  \"{rootValue}\" -> \"{childValue}\"";
    }

    private static void PrintNode<T>(T value, int empties)
    {
        //result += $"  empty{empties} [label=\"\", style=invis];";
        //result += $"  \"{value}\" -> empty{empties}";
    }

    private static void PrintSubTree<T>(AVLTree<T>.Node node, ref int empties)
    {

        if (node.left == null && node.right == null)
        {
            result += $"  \"{node.value}\" [shape=rectangle,xlabel={node.height}];";
            return;
        }
        result += $"  \"{node.value}\" [xlabel={node.height}];";

        if (node.left != null)
        {
            PrintNode(node.value, node.left.value);
            PrintSubTree(node.left, ref empties);
        }
        else if (node.right != null)
        {
            PrintNode(node.value, empties++);
        }

        if (node.right != null)
        {
            PrintNode(node.value, node.right.value);
            PrintSubTree(node.right, ref empties);
        }
        else if (node.left != null)
        {
            PrintNode(node.value, empties++);
        }
    }

    public static void PrintDot<T>(this AVLTree<T> tree, string writePath)
    {
        using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
        {
            result = "";
            int empties = 0;
            PrintSubTree(tree.root, ref empties);

            sw.WriteLine("digraph G {\n  forcelabels=true;");
            sw.WriteLine(result);
            sw.WriteLine("}");
        }
    }
}