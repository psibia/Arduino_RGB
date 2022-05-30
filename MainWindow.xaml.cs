using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;
using Sibia;

namespace Arduino
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        SerialPort sp = new SerialPort();
        string[] ports = SerialPort.GetPortNames();

        public MainWindow()
        {
            InitializeComponent();
            COM.ItemsSource = ports;
        }
        private void COM_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                if (sp.IsOpen)
                    sp.Close();
                sp.PortName = COM.SelectedItem as string;
                sp.BaudRate = 9600;
                sp.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Palette_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            SibiaLights.GetColors(Palette, e);
            // MessageBox.Show($"{SibiaLights.Red}   {SibiaLights.Green}   {SibiaLights.Blue}");
            sp.Write(SibiaLights.ColorsToArduino());
        }
    }
}
